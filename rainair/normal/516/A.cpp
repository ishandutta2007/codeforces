#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
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

const int MAXN = 20+5;
// 2! = 2!
// 3! = 3!
// 4! = 3! * 2! * 2!
// 5! = 5!
// 6! = 5! * 3!
// 7! = 7!
// 8! = 7! * 2! * 2! * 2!
// 9! = 7! * 2! * 3! * 3!
char str[MAXN];
int main(){
    int n;scanf("%d",&n);scanf("%s",str+1);
    std::vector<char> S;
    FOR(i,1,n){
        if(str[i] == '2' || str[i] == '3' || str[i] == '5' || str[i] == '7'){
            S.pb(str[i]);
        }
        if(str[i] == '4') S.pb('2'),S.pb('2'),S.pb('3');
        if(str[i] == '6') S.pb('5'),S.pb('3');
        if(str[i] == '8') S.pb('7'),S.pb('2'),S.pb('2'),S.pb('2');
        if(str[i] == '9') S.pb('7'),S.pb('2'),S.pb('3'),S.pb('3');
    }
    std::sort(all(S));std::reverse(all(S));
    for(auto x:S) printf("%c",x);puts("");
    return 0;
}