#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

string expr[256][2];
/// 0 : or
/// 1 : and

vector<pp> karanaru[256][2];

void add_global(int m, string e){
	expr[m][0]=e;
	expr[m][1]=e;
}

inline string conv(string e, int f, int t){
	if(f == 0 && t == 1) return '(' + e + ')';
	return e;
}

bool CMP(const string& a, const string& b){
	if(a.length() != b.length()) return a.length() < b.length();
	return a<b;
}

int main()
{
    add_global(0b11110000, "x");
    add_global(0b11001100, "y");
    add_global(0b10101010, "z");
    add_global(255^0b11110000, "!x");
    add_global(255^0b11001100, "!y");
    add_global(255^0b10101010, "!z");
    add_global(0, "x&!x");
    add_global(255, "x|!x");
    
    
    for(int i=0; i<256; ++i) for(int j=0; j<2; ++j) {
		if(j == 0){
			/// OR
			for(int a=1; a<256; ++a) for(int b=a+1; b<256; ++b){
				if(a==i || b==i) continue;
				if((a | b) == i){
					karanaru[i][0].eb(a, b);
				}
			}
		} else {
			/// AND
			for(int a=0; a<255; ++a) for(int b=a+1; b<255; ++b){
				if(a==i || b==i) continue;
				if((a & b) == i){
					karanaru[i][1].eb(a, b);
				}
			}
		}
	}
	
	const char* Chr = "|&";
    
    while(true){
		int Ce = 0;
		for(int m=0; m<256; ++m) for(int t=0; t<2; ++t) {
			int ce = 0;
			string& cur = expr[m][t];
			auto upd_cand = [&](string x){
				if(!cur.length()) ce=1, cur = x;
				else cur = min(cur, x, CMP);
			};
			for(auto tmp:karanaru[m][t]){
				int a, b; tie(a, b) = tmp;
				for(int ta=0; ta<2; ++ta) if(expr[a][ta].length()){
					for(int tb=0; tb<2; ++tb) if(expr[b][tb].length()){
						string pa = conv(expr[a][ta], ta, t);
						string pb = conv(expr[b][tb], tb, t);
						if(pa > pb) swap(pa, pb);
						string ret = pa + Chr[t] + pb;
						upd_cand(ret);
					}
				}
			}
			for(int j=0; j<2; ++j) if(expr[m^255][j].length()){
				upd_cand("!(" + expr[m^255][j] + ")");
			}
			Ce |= ce;
		}
		if(!Ce) break;
    }
    int n; read(n);
    for(;n--;){
		char buf[10]; scanf("%s", buf);
		int m = 0;
		for(int j=0; j<8; ++j) if(buf[j]=='1') m |= (1<<j);
		string ans = min(expr[m][0], expr[m][1], CMP);
		puts(ans.c_str());
    }
    return 0;
}