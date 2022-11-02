#include<bits/stdc++.h>
#define MAXN 500010
#define inf 1e+15
using namespace std;
multiset<int> b[100010];
int n,k,a[100010],tr[100010][26],tot,ch[100010],mi,mx;
long long ans;
string s[100010];
int check(int x){
    for (int i=0;i<k;i++){
        if (s[x][i]>s[x][k-i-1]) return 1;
        else if (s[x][i]<s[x][k-i-1]) return -1;
    }
    return 0;
}
int ins(int x){
    int now=0;
    for (int i=0;i<k;i++){
        if (!tr[now][s[x][i]-'a']) tr[now][s[x][i]-'a']=++tot;
        now=tr[now][s[x][i]-'a'];
    }
    return now;
}
int get(int x){
    int now=0;
    for (int i=0;i<k;i++){
        if (!tr[now][s[x][k-1-i]-'a']) return -1;
        now=tr[now][s[x][k-1-i]-'a'];
    }
    return now;
}
int main(){
    scanf("%d%d",&n,&k);
    mi=100000;
    mx=-100000;
    for (int i=0;i<n;i++){
        cin>>s[i];
        scanf("%d",&a[i]);
        ch[i]=check(i);
    }
    for (int i=0;i<n;i++)
    if ((ch[i]==0)){
        int o=ins(i);
        b[o].insert(a[i]);
    }
    for (int i=0;i<n;i++)
    if (ch[i]==0){
        int o=ins(i),to=0,past;
        for (multiset<int>::reverse_iterator it=b[o].rbegin();it!=b[o].rend();it++){
            if (to&&((*it)+past>0)){
                ans+=(*it)+past;
                mi=min(mi,*it);
            }
            else if (to) mx=max(mx,past);
            to^=1;
            past=*it;
        }
        if (to) mx=max(mx,past);
        b[o].clear();
    }
    long long tmp=max(ans-mi,ans+mx);
    ans=max(ans,tmp);
    for (int i=0;i<n;i++)
    if (ch[i]<0){
        int o=ins(i);
        b[o].insert(a[i]);
    }
    for (int i=0;i<n;i++)
    if (ch[i]>0){
        int o=ins(i);
        b[o].insert(a[i]);
        multiset<int>::iterator it=b[o].begin();
        ans+=(a[i]-*it);
        int p=get(i);
        if (p==-1) b[o].erase(it);
        else if (!b[p].empty()){
            multiset<int>::iterator j=b[p].end();
            j--;
            if (*j+*it>0){
                ans+=(*j+*it);
                b[p].erase(j);
            }
            else b[o].erase(it);
        }
        else b[o].erase(it);
    }
    printf("%lld\n",ans);
}