// Example program
#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define lli long long int
//#define cin in
//#define cout out
int inf = pow(10,9); 
int main()
{
	int n,k;
	cin>>n>>k;
	int a = 1, b = n;
	while(a<b)
	{
		int c = (a+b)/2;
		cout<<"1 "<<c+1<<" "<<c<<endl;
		string zz;
		cin>>zz;
		if(zz=="TAK")
		a = c+1;
		else
		b = c;
	}
	int kohne = a;
	b = n;
	while(kohne<b)
	{
		int orta = (kohne+b)/2;
		cout<<"1 "<<orta+1<<" "<<orta<<endl;
		string zz;
		cin>>zz;
		if(zz=="TAK"){ 
		 ++orta;
		 while(orta<b)
		 {
		 	int ortada = (orta+b)/2;
		 	cout<<"1 "<<ortada+1<<" "<<ortada<<endl;
		 	cin>>zz;
		 	if(zz=="TAK")
		 		orta = ortada + 1;
			else
			 	b = ortada;
		 }
		 cout<<"2 "<<orta<<" "<<kohne<<endl; return 0; 
		}
		else 
			b = orta;
	}
	a = 1;
	while(a<kohne)
	{
		int orta = (kohne+a+1)/2;
		cout<<"1 "<<orta-1<<" "<<orta<<endl;
		string zz;
		cin>>zz;
		if(zz=="TAK")
		{
			--orta;
			while(a<orta)
			{
			 	int ortada = (orta+a)/2;
		 		cout<<"1 "<<ortada+1<<" "<<ortada<<endl;
			 	cin>>zz;
		 		if(zz=="TAK")
		 			a = ortada + 1;
				else
				 	orta = ortada;
			 }
			 cout<<"2 "<<a<<" "<<kohne<<endl; return 0;
		}
		else
			a = orta;
	}
}