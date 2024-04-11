#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

typedef long long LL;

string s;
bool use[10];
int main() {
    cin>>s;
    LL ans=1;
    int d=10;
    if (isalpha(s[0])) {
	ans*=9;
	d--;
	use[s[0]-'A']=1;
    }
    if (s[0]=='?') ans*=9;
    
    for (int i=1; i<int(s.size()); i++) {
	if (s[i]=='?') ans*=10;
	if (isalpha(s[i]) && !use[s[i]-'A']) {
	    use[s[i]-'A']=1;
	    ans *= d;
	    d--;
	}
    }
    cout<<ans<<endl;
	
    return 0;
}