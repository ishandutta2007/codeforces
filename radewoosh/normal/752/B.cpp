#include <bits/stdc++.h>
using namespace std;

string a, b;

vector <char> graf[10007];

vector < pair <char,char> > wyn;

int main()
{
	cin >> a >> b;
	for (int i=0; i<a.size(); i++)
	{
		graf[a[i]].push_back(b[i]);
		graf[b[i]].push_back(a[i]);
	}
	for (char i='a'; i<='z'; i++)
	{
		if (graf[i].empty())
			graf[i].push_back(i);
		sort(graf[i].begin(), graf[i].end());
		if (graf[i][0]!=graf[i].back())
		{
			printf("-1\n");
			return 0;
		}
		if (i<graf[i][0])
			wyn.push_back({i, graf[i][0]});
	}
	printf("%d\n", (int)wyn.size());
	for (int i=0; i<wyn.size(); i++)
		printf("%c %c\n", wyn[i].first, wyn[i].second);
	return 0;
}