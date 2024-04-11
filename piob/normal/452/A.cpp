#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

vector<string> V{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int n;

int main(){
    string S;
    cin >> n >> S;
    for(string T : V){
        if(T.size() != S.size()) continue;
        bool ok = 1;
        FWD(i,0,n)
            if(T[i] != S[i] && S[i] != '.')
                ok = 0;
        if(ok){
            cout << T << endl;
            return 0;
        }
    }
    return 0;
}