#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

double pow(double a, int p){
    double b = 1;
    while(p){
        if(p&1) b *= a;
        a *= a;
        p /= 2;
    }
    return b;
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    double res = 0;
    FWD(k,1,m+1){
        res += k * (pow(k/(double)m, n) - pow((k-1)/(double)m, n));
    }
    cout.precision(5);
    cout << fixed << res << endl;   
    return 0;
}