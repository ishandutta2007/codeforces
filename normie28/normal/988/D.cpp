#include<bits/stdc++.h>
using namespace std;
set<int>s;
int main() {
	int tmp,n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>tmp;
		s.insert(tmp);
	}
	for(int i:s) {
		for(int j=0;j<31;j++){
			int bit=(1<<j);
			if(s.count(i-bit)&&s.count(i+bit))
				return!(cout<<"3"<<endl<<i-bit<<" "<<i<<" "<<i+bit<<endl);
		}
	}
	for(int i:s) {
		for(int j=0;j<31;j++){
			int bit=(1<<j);
			if(s.count(i-bit))
				return!(cout<<"2"<<endl<<i-bit<<" "<<i<<endl);
		}
	}
	cout<<1<<endl<<*s.begin()<<endl;
}