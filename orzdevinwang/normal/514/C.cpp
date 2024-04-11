#include<bits/stdc++.h>
#define N 600007
using namespace std;


// three mod hash ----------------------------------
const int moda = 998244353;
const int modb = 1004535809;
const int modc = 1e9 + 7;
const int G = 917120411;
int qpowa[N], qpowb[N], qpowc[N];
struct thash { int vala, valb, valc; };
void init(int x) {qpowa[0] = qpowb[0] = qpowc[0] = 1;for(int i = 1; i <= x; i++) qpowa[i] = 1ll * qpowa[i - 1] * G % moda, qpowb[i] = 1ll * qpowb[i - 1] * G % modb, qpowc[i] = 1ll * qpowc[i - 1] * G % modc;}
bool operator == (thash aa, thash bb) {return aa.vala == bb.vala && aa.valb == bb.valb && aa.valc == bb.valc;} 
bool operator < (thash aa, thash bb) {return aa.vala == bb.vala ? (aa.valb == bb.valb ? aa.valc < bb.valc : aa.valb < bb.valb) : aa.vala < bb.vala; }
bool operator > (thash aa, thash bb) {return aa.vala == bb.vala ? (aa.valb == bb.valb ? aa.valc > bb.valc : aa.valb > bb.valb) : aa.vala > bb.vala; }
thash operator + (thash aa, int bb) {thash p;p.vala = ((aa.vala + bb) % moda + moda) % moda;p.valb = ((aa.valb + bb) % modb + modb) % modb;p.valc = ((aa.valc + bb) % modc + modc) % modc;return p;}
thash operator + (thash aa, thash bb) {thash p; p.vala = ((aa.vala + bb.vala) % moda + moda) % moda; p.valb = ((aa.valb + bb.valb) % modb + modb) % modb;p.valc = ((aa.valc + bb.valc) % modc + modc) % modc; return p;}
thash operator * (thash aa, int bb) { thash p; p.vala = 1ll * aa.vala * (bb + moda) % moda; p.valb = 1ll * aa.valb * (bb + modc) % modb; p.valc = 1ll * aa.valc * (bb + modc) % modc; return p;}
thash operator << (thash aa, int bb) { thash p; p.vala = 1ll * aa.vala * qpowa[bb] % moda; p.valb = 1ll * aa.valb * qpowb[bb] % modb; p.valc = 1ll * aa.valc * qpowc[bb] % modc; return p; }
thash make(int aa) { thash p; p.vala = (aa % moda + moda) % moda; p.valb = (aa % modb + modb) % modb; p.valc = (aa % modc + modc) % modc; return p; }
thash clean() {thash p; p.vala = p.valb = p.valc = 0; return p;}
// end hash ----------------------------------------

int n, m, len, qpow[N];
map<thash, bool> mp;
char s[N];
bool cheak() {
	len = strlen(s + 1);
	thash has = clean();
	for(int i = 1; i <= len; i++) has = has + (make(s[i] - 'a' + 1) << i);
	if(mp[has]) return 1;
	return 0;
}
int main() {
	init(600000);
	scanf("%d%d", &n, &m);
	while(n--) {
		scanf("%s", s + 1);
		len = strlen(s + 1);
		thash has = clean();
		for(int i = 1; i <= len; i++) has = has + (make(s[i] - 'a' + 1) << i);
		for(int i = 1; i <= len; i++) 
			for(char j = 'a'; j <= 'c'; j++) 
				if(j != s[i]) 
					mp[has + (make(j - s[i]) << i)] = 1;
	}
	while(m--) {
		scanf("%s", s + 1);
		printf("%s\n", cheak() ? "YES" : "NO");
	}
	return 0;
}