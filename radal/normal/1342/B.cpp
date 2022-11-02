#include <iostream>
#include <cmath>
using namespace std;
/*
void msort(int l,int r){
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid);
	msort(mid, r);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<mid)){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
			if (a[p1]>a[p2]){
				tt++;
				cout<<a[p1]<<a[p2]<<endl;
		}
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}*/
struct node{
	char val;
	node* p;
};

int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		string s,t="";
		bool f1=0,f0=0;
		cin >> s;
		for (int j = 0; j<s.size(); j++){
			if (s[j] == '1'){
				f1=1;
			}
			if (s[j] == '0'){
				f0 = 1;
			}
		}
		if (!f0 or !f1){
			cout<<s<<endl;
			continue;
		}
		else{
			int k=1;
			t+=s[0];
			for (int j=1; j<s.size(); j++){
				if (s[j] == s[j-1]){
					if (s[j] == '1'){
						t+='0';
						t+='1';
						k += 2;
					}
					if (s[j] == '0'){
						t+='1';
						t+='0';
						k += 2;
					}
				}
				else{
					t+=s[j];
				}
			}
		}
		cout<<t<<endl;
	}
}