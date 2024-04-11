#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int a[N];
int bit[N];
void upd(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1) bit[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--){
        sum+=bit[pos];
    }
    return sum;
}
int l[N];
int L[N];
int R[N];
vector<int>Q[N];
int ans[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i],a[i]-=i;
    if (a[1]==0) l[1]=1;
    else l[1]=0;
    upd(n,l[1],1);
    for (int i=2;i<=n;i++){
        l[i]=0;
        if (a[i]<=0){
            for (int j=20;j>=0;j--){
                if (l[i]+(1<<j)>i) continue;
                l[i]+=(1<<j);
                int cnt=i-1-get(l[i]-1);
                if ((-a[i])>cnt){
                    l[i]-=(1<<j);
                }
            }
        }
        upd(n,l[i],1);
    }
    for (int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        L[i]=x+1;
        R[i]=n-y;
        Q[R[i]].push_back(i);
    }
    for (int i=0;i<=n;i++) bit[i]=0;
    for (int i=1;i<=n;i++){
        upd(n,l[i],1);
        for (int j:Q[i]){
            int cnt=i-get(L[j]-1);
            ans[j]=cnt;
        }
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<endl;
    return 0;
}

/*
0 2 3 5 3 5 3 5 5 2 5 13
    for (int i=2;i<=n;i++){
        l[i]=0;
        if (a[i]<=0){
            for (int j=20;j>=0;j--){
                if (l[i]+(1<<j)>i) continue;
                l[i]+=(1<<j);
                int cnt=i-1-get(l[i]-1);
//                for (int t=1;t<i;t++){
//                    cnt+=(l[t]>=l[i]);
//                }
                if ((-a[i])>cnt){
                    l[i]-=(1<<j);
                }
            }
        }
        cout<<l[i]<<" ";
        upd(n,l[i],1);
    }
*/