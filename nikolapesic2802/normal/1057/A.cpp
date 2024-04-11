#include <bits/stdc++.h>
#define ll long long
using namespace std;
char c;
int n,m,h1,h2,poz,i,h3,test;
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	scanf("%i",&n);
	vector<int> niz(n+1);
	for(int i=2;i<=n;i++)
	{
		//cin >> niz[i];
		scanf("%i",&niz[i]);
	}
	stack<int> s;
	int tr=n;
	while(tr!=1)
	{
		//cout << tr << " ";
		s.push(tr);
		tr=niz[tr];
	}
	s.push(tr);
	while(s.size()!=1)
	{
		printf("%i ",s.top());
		//cout << s.top() << " ";
		s.pop();
	}
	printf("%i\n",s.top());
	//cout << s.top() << "\n";
	return 0;
}