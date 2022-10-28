#include<bits/stdc++.h>
using namespace std;
long long sum(long long x){
    long long temp = x;
    temp*=x+1;
    temp>>=1;
    return temp;
}
long long dif(long long x,long long y){
    long long temp = sum(y)-sum(x-1);
    return temp;
}
long long a,b,n;
bool comp(long long l,long long m,long long t,long long r){
    long long x = a + (r-1)*b;
    if(x>t){
        return 0;
    }
    x = (r-l+1)*a;
    x += b*(dif(l-1,r-1));
    return x<=(m*t);
}
int main(){
    cin>>a>>b>>n;
    while(n--){
        long long l,t,m;
        cin>>l>>t>>m;
        if((a + (l-1)*b)>t){
            printf("-1\n");
            continue;
        }
        long long L = l;
        long long R = 1000001LL;
        while(L<R){
            long long mid = (L+R)>>1;
            if(comp(l,m,t,mid)){
                L= mid+1;
            }
            else{
                R=mid;
            }
        }
        if((L-1)<l){
            printf("-1\n");
            continue;
        }
        printf("%I64d\n",L-1);
    }
}