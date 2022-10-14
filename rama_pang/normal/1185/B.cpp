#include <bits/stdc++.h>
using namespace std;
string a,b;

int main (){
	int T;
	cin >> T;
	while (T--){
		cin >> a >> b;
		if (a.size()>b.size()){
			cout << "NO\n";
			continue;
			
		} else if (a.size()==b.size()){
			if (a==b){
				cout << "YES\n";
			} else{
				cout << "NO\n";
			}
			continue;
		}
		int loc=0;
		int i=0;
		int cek=0;
		//while (loc<b.size()){
			//if(a[i]==b[loc]){
				//loc++;
				//if (a[i+1]==a[i]){
					//if (a[i+1]!=b[loc]){
						//cek=1;
						//break;
					//}
					//i++;
				//}
			//} else{
				//if (a[i+1]==b[loc]){
					//i++;
					//continue;
				//}
				//cek=1;
				//break;
			//}
			
		//}
		int prev=0;
		while (i<a.size() or loc<b.size()){
			//if (loc==b.size()){
				//cek=1;
				//break;
			//}
			
			if (a[i]==b[loc]){
				prev=i;
				i++;
				loc++;
				if (a[prev]==a[i]){
					continue;
				}
				
				while (b[loc]==a[prev]){
					loc++;
				}
				continue;
			}
			cek=1;
			break;
		}
		if (cek==1){
			cout << "NO\n";
		} else{
			cout << "YES\n";
		}
	}
}