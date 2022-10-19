#include <iostream>
#include <algorithm>

using namespace std;

int n , k;
int t[200010];
int x[200010] , y[200010] , z[200010];
int cntx , cnty , cntz;

bool cmp(int a , int b)
{
	return t[a] < t[b];
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		int a , b;
		cin >> t[i] >> a >> b;
		if(a == 1 && b == 1)
			z[++cntz] = i;
		else if(a == 1)
			x[++cntx] = i;
		else if(b == 1)
			y[++cnty] = i;	
	}
	if(cntz + cntx < k || cntz + cnty < k)
	{
		cout << -1 << endl;
		return 0;
	}
	sort(x + 1 , x + cntx + 1 , cmp);
	sort(y + 1 , y + cnty + 1 , cmp);
	sort(z + 1 , z + cntz + 1 , cmp); 
	int ans = 0 , temp1 = 1 , temp2 = 1;
	for(int i = 1; i <= k; i++)
	{
		if(temp1 > min(cntx , cnty))
		{
			ans += t[z[temp2]];
			temp2++; 
		}
		else if(temp2 > cntz)
		{
			ans += t[x[temp1]] + t[y[temp1]];
			temp1++;
		} 
		else if(t[x[temp1]] + t[y[temp1]] < t[z[temp2]])
		{
			ans += t[x[temp1]] + t[y[temp1]];
			temp1++;
		}
		else
		{
			ans += t[z[temp2]];
			temp2++; 
		}
	}
	cout << ans << endl;
	return 0;
}