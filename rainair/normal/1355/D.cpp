#include<bits/stdc++.h>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
int n,s;
inline void Fxxk(){
    if(s >= 2*n){
        puts("YES");
        FOR(i,1,n-1) printf("%d ",2);
        printf("%d\n",s-2*(n-1));
        puts("1");return;
    }
    puts("NO");

}

int main(){
            scanf("%d%d",&n,&s);

    Fxxk();
    return 0;
}