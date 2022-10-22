#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool is_vowel(char c) {
	return c=='a'||c=='e'||c=='u'||c=='o'||c=='i';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	/*int ans=0;
	for (int a=0; a<5; ++a) for (int b=0; b<5; ++b) for (int c=0; c<5; ++c)
		for (int d=0; d<5; ++d) for (int e=0; e<5; ++e) for (int f=0; f<5; ++f) {
			if (a==d&&b==e&&c==f)
				continue;
			int x=a-d, y=b-e, z=c-f;
			if (x) {
				ans+=y*y-4*x*z>=0;
			} else {
				ans+=y!=0;
			}
		}
	ans/=2;
	cout << ans;*/
	string s;
	cin >> s;
	for (int i=0; i+1<s.size(); ++i) {
		if (!is_vowel(s[i])&&s[i]!='n'&&!is_vowel(s[i+1])) {
			cout << "NO";
			return 0;
		}
	}
	cout << (is_vowel(s.back())||s.back()=='n'?"YES":"NO");
	return 0;
}