#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <deque>
#include <cstring>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define REP(a,c) for(int a=0; a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, k;
long long a, b, c;
 long long x;
 long long T[100010];
 long long S[100010];
 long long R[100010];

//(n+k-2-i)/k

 long long get(long long a, long long b){
    if(b > n-1) b = n-1;
    if(a < 0) a = 0;
    if(a > b) return 0;
    if(a == 0) return S[(int)b];
    return S[(int)b] - S[(int)a-1];
}

int main(){
    cin >> n;
    FWD(i,0,n) cin >> T[i];
    sort(T,T+n);
    reverse(T,T+n);
    S[0] = T[0];
    FWD(i,1,n) S[i] = S[i-1] + T[i];
    FWD(i,0,100010) R[i] = -1;
    cin >> m;
    FWD(i,0,m){
        cin >> k;
        if(R[k] == -1){
            R[k] = 0;
            x = 0;
            a = 0;
            b = 0;
            c = 1;
            while(++x){
                a = b + 1;
                c = k*c;
                b = b + c;
                if(a >= (long long)n) break;
                R[k] += x*get(a,b);
            }
        }
        cout << R[k] << " ";
    }
    cout << endl;
    return 0;
}