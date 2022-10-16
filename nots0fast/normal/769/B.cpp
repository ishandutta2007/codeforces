#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <iomanip>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define forl(v) for(int l=0; l<v; l++)
#define mp(a,b) make_pair(a,b)
#define ff first
#define lli long long int
#define ss second
bool John (pair<int,int> a, pair<int,int> b)
{
	return a.ff > b.ff;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > xamisi;
    vector<pair<int,int> > otpravka;
    xamisi.resize(n);
    fori(n)
    {
    	cin>>xamisi[i].ff;
    	xamisi[i].ss=i;
	}
	sort(xamisi.begin()+1,xamisi.end(),John);
	int zapas = 1;
	int qalmiwiq = 1;
	int i = 0;
	while(i<xamisi.size())
	{
		--zapas;
		if(zapas<0)
		{
			cout<<-1;
			return 0;
		}
		zapas+=xamisi[i].ff;
		int blur = xamisi[i].ff;
		while(blur>0 && qalmiwiq<xamisi.size())
		{
			otpravka.push_back(mp(xamisi[i].ss+1,xamisi[qalmiwiq].ss+1));
			--blur;
			++qalmiwiq;
		}
		++i;
	}
	cout<<otpravka.size()<<endl;
	forj(otpravka.size())
	{
		cout<<otpravka[j].ff<<" "<<otpravka[j].ss<<endl;
	}
}