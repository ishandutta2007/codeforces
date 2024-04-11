#include <bits/stdc++.h>
using namespace std;
int main() {
  int diff=0,cnt=0;
char c;
	while (cin>>c) 
	if (c=='(') diff++;
	else  if (diff) {diff--; cnt++;}
	cout<<cnt*2;
}