#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    return x;
}
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define author rajat1603
#define N 100001
#define inf 2147483646
long long steps=0;
void gcd(long long a,long long b){
    while(b){
        long long t=(long long)a;
        t/=b;
        steps+=t;
        long long temp= a%b;
        a=b;
        b=temp;
    }
}
int main(){
    long long a,b;
    cin>>a>>b;
    gcd(a,b);
    printf("%I64d\n",steps);
}