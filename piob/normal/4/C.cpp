#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
map<string, int> M;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        string s;
        cin >> s;
        if(M.find(s) == M.end()){
            printf("OK\n");
            M[s] = 1;
        }else{
            printf("%s%d\n", s.data(), M[s]);
            ++M[s];
        }
    }
    return 0;
}