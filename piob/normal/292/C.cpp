#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

typedef long long LL;

int n;
int D[6];
int C[6];
vector<string> res;

bool ran(string a){
    int r = a[0] - '0';
    if(a.size() > 1)
        r = 10*r + (a[1] - '0');
    if(a.size() > 2)
        r = 10*r + (a[2] - '0');
    return 0 <= r && r < 256;
}

bool lz(string a){
    return a.size() > 1 && a[0] == '0';
}

void traj(string a, string b, string c, string d){
    if(d.size() > 3 || d.size() < 1) return;
    if(lz(a) || lz(b) || lz(c) || lz(d))
        return;
    if(!ran(c) || !ran(d))
        return;
    bool W[10]; FWD(i,0,10) W[i] = 0;
    FWD(i,0,a.size()) W[a[i]-'0'] = 1;
    FWD(i,0,b.size()) W[b[i]-'0'] = 1;
    FWD(i,0,c.size()) W[c[i]-'0'] = 1;
    FWD(i,0,d.size()) W[d[i]-'0'] = 1;
    FWD(i,0,n) if(!W[D[i]]) return;
    res.push_back(a + "." + b + "." + c + "." + d);
}

void traj(string a, string b, string c){
    if(c.size() > 6) return;
    if(!ran(b)) return;
    FWD(i,1,min(4,(int)c.size()))
        traj(a, b, c.substr(0,i), c.substr(i)); 
}

void traj(string a, string b){
    if(b.size() > 9) return;
    if(!ran(a)) return;
    FWD(i,1,min(4,(int)b.size()))
        traj(a, b.substr(0,i), b.substr(i));
}

void traj(string a){
    FWD(i,1,min(4,(int)a.size()))
        traj(a.substr(0,i), a.substr(i));
}

void checkout(int len){
    string s;
    FWD(i,0,len)
        s += C[i] + '0';
    BCK(i,len-1,-1)
        s += C[i] + '0';
    traj(s);
    s.clear();
    FWD(i,0,len-1)
        s += C[i] + '0';
    BCK(i,len-1,-1)
        s += C[i] + '0';
    traj(s);
}

void gen(int pos = 0){
    FWD(i,0,n){
        C[pos] = D[i];
        if(pos < 5)
            gen(pos+1);
        checkout(pos+1);
    }
}

int main(){
    scanf("%d", &n);
    if(n > 6){
        printf("0\n");
        return 0;
    }
    FWD(i,0,n)
        scanf("%d", &D[i]);
    gen();
    printf("%d\n", (int)res.size());
    FWD(i,0,(int)res.size())
        printf("%s\n", res[i].c_str());
    return 0;
}