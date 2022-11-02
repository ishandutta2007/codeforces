#include <bits/stdc++.h>
using namespace std;

char tab[57][57];
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		set<int> wiersz,kolumna;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>tab[i][j];
				if(tab[i][j]=='1')
				{
					wiersz.insert(i);
					kolumna.insert(j);
				}
			}
		}
		if(min(n-wiersz.size(),m-kolumna.size())%2==0) cout<<"Vivek"<<endl;
		else cout<<"Ashish"<<endl;
	}
	return 0;
}