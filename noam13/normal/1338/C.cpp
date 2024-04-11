#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;

int per[] = {0,2,3,1};
int getsec(int n){
	if (n==0) return 0;
	return per[n%4]+4*getsec(n/4);
}
int solve(){
    int n; cin>>n;
    int who = (n-1)%3;
    int base = -1;
    loop(i,0,30){
    	int pp = int(1)<<(2*i);
    	base = i;
    	if (pp>n) break;
    }
    base--;
    base = int(1)<<(2*base);
    int ans = (who+1)*base;
    n-=base; n/=3;
    int fir = n;
    int sec = getsec(n);
    int thir = fir^sec;
    if (who==0) ans+=fir;
    if (who==1) ans+=sec;
    if (who==2) ans+=thir;
    cout<<ans<<endl;
    return 0;
}
/*
int n;
vb check;
vi ans;

bool can(){
	loop(i,1,n){
		if (check[i]) continue;
		loop(j,i+1,n){
			if (check[j]) continue;
			loop(k,j+1,n){
				if (check[k]) continue;
				if (i^j^k) continue;
				check[i] = check[j] = check[k] = 1;
				ans.pb(i); ans.pb(j); ans.pb(k);
				return 1;
			}
		}
	}
	return 0;
}
void brute(int x){
	n = x;
	check = vb(n);
	ans.clear();
	while(can());
	loop(i,0,ans.size()) cout<<ans[i]<<" "<<(i%3==2?"\n":""); cout<<endl;
}*/
int32_t main(){
    ios_base::sync_with_stdio(false);
    //brute(257);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
9
1
2
3
4
5
6
7
8
9



1 2 3 
4 8 12 
5 10 15 
6 11 13 
7 9 14 
16 32 48 
17 34 51 
18 35 49 
19 33 50 
20 40 60 
21 42 63 
22 43 61 
23 41 62 
24 44 52 
25 46 55 
26 47 53 
27 45 54 
28 36 56 
29 38 59 
30 39 57 
31 37 58 
64 128 192 
65 130 195 
66 131 193 
67 129 194 
68 136 204 
69 138 207 
70 139 205 
71 137 206 
72 140 196 
73 142 199 
74 143 197 
75 141 198 
76 132 200 
77 134 203 
78 135 201 
79 133 202 
80 160 240 
81 162 243 
82 163 241 
83 161 242 
84 168 252 
85 170 255 
86 171 253 
87 169 254 
88 172 244 
89 174 247 
90 175 245 
91 173 246 
92 164 248 
93 166 251 
94 167 249 
95 165 250 
96 176 208 
97 178 211 
98 179 209 
99 177 210 
100 184 220 
101 186 223 
102 187 221 
103 185 222 
104 188 212 
105 190 215 
106 191 213 
107 189 214 
108 180 216 
109 182 219 
110 183 217 
111 181 218 
112 144 224 
113 146 227 
114 147 225 
115 145 226 
116 152 236 
117 154 239 
118 155 237 
119 153 238 
120 156 228 
121 158 231 
122 159 229 
123 157 230 
124 148 232 
125 150 235 
126 151 233 
127 149 234
*/