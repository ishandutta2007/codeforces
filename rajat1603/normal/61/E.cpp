#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define getchar_unlocked getchar
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
const int N = 1000009;
long long bit1[N]={0};
long long bit2[N]={0};
int n;
pair<int,int> arr[N];
void update(long long *f,int i,long long val){
    while(i<=n){
        f[i]+=val;
        i+=i&-i;
    }
}
long long query(long long *f,int i){
    long long res=0;
    while(i){
        res+=f[i];
        i&=i-1;
    }
    return res;
}
int main(){
    n=scan();
    for(int i=1;i<=n;++i){
        arr[i].first=scan();
        arr[i].second=i;
    }
    sort(arr+1,arr+1+n);
    long long answer=0;
    for(int i=n;i>=1;--i){
        update(bit1,arr[i].second,1);
        update(bit2,arr[i].second,query(bit1,arr[i].second-1));
        answer+=query(bit2,arr[i].second-1);
    }
    printf("%I64d",answer);
}