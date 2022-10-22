#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef long double ld;
typedef pair<ld,li> pdi;
typedef pair<li,li> pll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back

li sum, n, i, j, c, k, a;
string s;
bool ch;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (i=0; i<n; i++){
		cin >> a >> s;
		if (sum==0){
			if (s!="South"){
				ch=1;
				break;
			}
		}
		else if (sum==20000){
			if (s!="North"){
				ch=1;
				break;
			}
		}
		if (s=="South"){
			sum+=a;
		}
		else if (s=="North") sum-=a;
		if (sum>20000 || sum<0){
			ch = 1;
			break;
		}
	}
	if (ch||sum!=0) cout << "NO";
	else cout << "YES";
}