#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x,m,h;
	cin>>x;
	cin>>h>>m;
	int count=0;
	bool b=false;
	while(!b){
		if(h%10==7){
			b=true;
		}
		else if(m%10==7){
			b=true;
		}
		else{
			m-=x;
			count++;
			if(m<0){
				m+=60;
				h--;
				if(h<0)
					h+=24;
			}
		}
	}
	cout<<count;
}