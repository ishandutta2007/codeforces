#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

string s;
int main() {
    cin>>s;
    if (s[0]=='h') {
	printf("http://%c", s[4]);
	
	s=s.substr(5);
    } else {
	printf("ftp://%c", s[3]);
	s=s.substr(4);
    }
    int p=s.find("ru");
    cout<<s.substr(0, p)<<'.'<<"ru";
    if (p+2 < int(s.size())) {
	cout<<'/'<<s.substr(p+2);
    }
    puts("");

    return 0;
}