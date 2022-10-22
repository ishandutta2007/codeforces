#include <bits/stdc++.h>
using namespace std;
typedef long long int li;
typedef pair<int,int> pi;
typedef pair<li,li> pl;
li n, i, a, b, c, k, ones, ch, ch1, sz, ans=0, ans1=0;
string s, s1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	a--;
	ones = 0;
	ch=0;
	for (k=66; k>=0; k--){
		if (pow(2,k)<=b){
			ch=1;
			c = pow(2,k);
			b-=c;
			s+='1';
		}
		else {
			if (ch==1) s+='0';
		}
	}
	sz = s.size();
	ch = 0;
	ch1 = 0;
	for (i=0; i<sz; i++){
		if (s[i]=='1'&&ch==0) ones++;
		else if (s[i]=='0'&&ch==0) ch=1;
		else if (ch==1&&s[i]=='0') ch1=1;
	}
	if (ch1==0&&ch==1) ans++;
	ans=ans+ones-1;
	sz=sz-2;
	ans = ans + (sz*(sz+1))/2;
	
	ones = 0;
	ch=0;
	for (k=66; k>=0; k--){
		if (pow(2,k)<=a){
			ch=1;
			c = pow(2,k);
			a-=c;
			s1+='1';
		}
		else {
			if (ch==1) s1+='0';
		}
	}
	sz = s1.size();
	ch = 0;
	ch1 = 0;
	for (i=0; i<sz; i++){
		if (s1[i]=='1'&&ch==0) ones++;
		else if (s1[i]=='0'&&ch==0) ch=1;
		else if (ch==1&&s1[i]=='0') ch1=1;
	}
	if (ch1==0&&ch==1) ans1++;
	ans1=ans1+ones-1;
	sz=sz-2;
	ans1 = ans1 + (sz*(sz+1))/2;
	cout << ans-ans1;
}