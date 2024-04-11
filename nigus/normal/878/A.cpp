#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
int n,m,k,q,w,h,T;

vector<int> A;
vector<char> CH;

int eva(int x, int i, int bit){
    int b = ((1 << bit)&A[i])!=0;
    if(CH[i] == '|')return x|b;
    if(CH[i] == '^')return x^b;
    if(CH[i] == '&')return x&b;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d;

    scanf("%d",&n);
    for(ll c1 = 0; c1 < n; c1++){
        char ch;
        scanf("%s",&ch);
        scanf("%d",&a);
        CH.push_back(ch);
        A.push_back(a);
    }

    int ior = 0;
    int ixor = 0;
    int iand = 1023;

    for(ll c1 = 0; c1 < 10; c1++){
        c = (1 << c1);
        a = 1;
        for(ll c2 = 0; c2 < n; c2++){
            a = eva(a,c2,c1);
        }
        b = 0;
        for(ll c2 = 0; c2 < n; c2++){
            b = eva(b,c2,c1);
        }

        if(a == 1 && b == 1){
            ior += c;
        }
        if(a == 0 && b == 1){
            ixor += c;
        }
        if(a == 0 && b == 0){
            iand -= c;
        }
    }

    cout << "3\n";
    cout << "& " << iand << "\n";
    cout << "| " << ior << "\n";
    cout << "^ " << ixor << "\n";

    return 0;
}