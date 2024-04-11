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
    int n=scan(),m=scan();
    int sum=0;
    while(n>=1&&m>=1&&n+m>2){
        if(n>m){
            sum++;
            n-=2;
            m--;
        }
        else{
            sum++;
            m-=2;
            n--;
        }
    }
    cout<<sum;
}