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
const int N = 300011;
const int mod = 1e9 + 9;
int arr[N]={0};
int fib[N]={0};
int mark[N]={0};
int n,q;
int LL[N];
int RR[N];
inline void init(){
    fib[0]=0;
    fib[1]=1;
    int a=0,b=1,c;
    for(int i=2;i<N;++i){
        c=a+b;
        if(c>=mod){
            c-=mod;
        }
        fib[i]=fib[i-1]+c;
        if(fib[i]>=mod){
            fib[i]-=mod;
        }
        a=b;
        b=c;
    }
}
int main(){
    n=scan(),q=scan();
    int sqn = sqrt(q);
    arr[0]=0;
    for(int i=1;i<=n;++i){
        arr[i]=arr[i-1]+scan();
        if(arr[i]>=mod){
            arr[i]-=mod;
        }
    }
    init();
    int sz=0;
    mark[0]=0;
    while(q--){
        if(sz==sqn){
            int sum=mark[1];
            arr[1]+=sum;
            if(arr[1]>=mod){
                arr[1]-=mod;
            }
            for(int i=2;i<=n;++i){
                mark[i]+=(mark[i-1]+mark[i-2])%mod;
                while(mark[i]>=mod){
                    mark[i]-=mod;
                }
                while(mark[i]<0){
                    mark[i]+=mod;
                }
                sum+=mark[i];
                if(sum>=mod){
                    sum-=mod;
                }
                arr[i]+=sum;
                if(arr[i]>=mod){
                    arr[i]-=mod;
                }
                mark[i-2]=0;
            }
            mark[n-1]=0;
            mark[n]=0;
            sz=0;
        }
        int type=scan(),l=scan(),r=scan();
        if(type&1){
            mark[l]++;
            mark[r+1]-=fib[r-l+2]-fib[r-l+1];
            mark[r+2]-=fib[r-l+1]-fib[r-l];
            while(mark[r+1]<0){
                mark[r+1]+=mod;
            }
            while(mark[r+2]<0){
                mark[r+2]+=mod;
            }
            while(mark[r+1]>=mod){
                mark[r+1]-=mod;
            }
            while(mark[r+2]>=mod){
                mark[r+2]-=mod;
            }
            LL[sz]=l;
            RR[sz]=r;
            ++sz;
        }
        else{
            int res=0;
            res=arr[r];
            res-=arr[l-1];
            if(res<0){
                res+=mod;
            }
            for(int i=0;i<sz;++i){
                int L = LL[i];
                int R = RR[i];
                if(R<l||L>r){
                    continue;
                }
                else if(L>=l&&R<=r){
                    res+=fib[R-L+1];
                }
                else if(L>=l){
                    res+=fib[r-L+1];
                }
                else if(R<=r){
                    res+=fib[R-L+1]-fib[l-L];
                }
                else if(L<=l&&r<=R){
                    res+=fib[r-L+1]-fib[l-L];
                }
                if(res>=mod){
                    res-=mod;
                }
                else if(res<0){
                    res+=mod;
                }
            }
            printf("%d\n",res);
        }
    }
}