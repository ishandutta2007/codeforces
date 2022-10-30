#include<bits/stdc++.h> 
using namespace std;  
int main(){
	long long int t;
	cin >> t;
	for (int p=0; p<t; p++){
		string s;
		cin >> s;
		long long int a=0,b=0;
		for (int i=0; i<s.size(); i++){
			if (s[i] == '0'){
				b++;
			}
			else{
				a++;
			}
		}
		if (min(a,b)%2) cout<<"DA"<<endl;
		else cout<<"NET"<<endl;
	}
	
}