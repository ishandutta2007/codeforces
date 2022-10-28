#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define getchar_unlocked getchar//for codeforces and timus
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
int main(){
    int n=scan();
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=scan();
    }
    long long temp=sum;
    for(int i=1;i<n;i++){
        temp-=scan();
    }
    printf("%I64d\n",temp);
    sum-=temp;
    for(int i=2;i<n;i++){
        sum-=scan();
    }
    printf("%I64d",sum);
}