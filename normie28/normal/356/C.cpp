#include <iostream>
#include <vector>
using namespace std;
int moveCandy(vector<int> Candy)
{
	int n = Candy.size(), sum = 0, i, c[5] = { 0,0,0,0,0 };
	for (i = 0; i < n; i++) { c[Candy[i]]++; sum += Candy[i]; }
	if ((sum == 0) or (sum == 1) or (sum == 2) or (sum == 5)) return -1;
	int res = 0;
	res = (c[1] < c[2]) ? c[1] : c[2];
	c[3] += res;
	c[1] -= res;
	c[2] -= res;
	if (c[1]) while (c[1]>0)
	{
	if (c[1]<=0) return res;
		if (c[1] % 3 == 0) { res += c[1] / 3 * 2; return res; }
		c[3] += c[1] / 3; res += c[1] / 3 * 2; c[1] %= 3;
		int pairs=c[1]/2;
		int able=pairs;
		if (able>c[4]) able=c[4];
		c[1] -= able*2; c[3] += able*2; c[4] -=able;
		res+=able*2;
		if (c[3] >= c[1]) {
			res += c[1]; return res;
		}
		c[1] -= c[3];  c[4] += c[3]; res += c[3];c[3] = 0;
		if (c[1] * 2 <= c[4]) { res += c[1] * 2; return res; }
		c[1] -= c[4] / 2; c[3] += c[4] / 2; c[4] %= 2;
	res+=c[1]/2;
	c[2]+=c[1]/2;
	c[1]%=2;
	}
	if (c[2]) while (c[2]>0)
	{
		
		if (c[2] % 3 == 0) { res += c[2] / 3 * 2; return res; }
		c[3] += c[2] / 3 * 2; res += c[2] / 3 * 2; c[2] %= 3;
//		cout<<c[2]<<' '<<res<<endl;
		if (c[2] % 2 == 0) { res += c[2] / 2*2; return res; }
		c[4] += c[2] / 2; res += c[2] / 2*2; c[2] %= 2;
		if (c[4] >= c[2]) {
			res += c[2]; return res;
		}
		c[2] -= c[4]; c[3] += c[4]; res += c[4]; c[4] = 0;
		if (c[2] * 2 <= c[3]) { res += c[2] * 2; return res; }
		res += c[3]/2*2;
		c[2] -= c[3] / 2; c[4] += c[3] / 2; c[3] %= 2;
	}
	return res;
}
int main ()
{
    int n;
    cin>>n;
    vector<int> v; 
    int a;
    for (int i=0;i<n;i++) {cin>>a; v.push_back(a);}
    cout<<moveCandy(v);
}