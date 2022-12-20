#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int dx[2000000],dy[2000000],cid[2000000];
int di[2000000],dj[2000000];

bool cmp(int a,int b)
{
	if(dx[a]==dx[b]) return dy[a]<dy[b];
	return dx[a]<dx[b];
}

int x[2000],y[2000];

bool ispar(int a,int b,int c,int d)
{
	return (x[a]+x[c]==x[b]+x[d] && y[a]+y[c]==y[b]+y[d])
	|| (x[a]+x[d]==x[b]+x[c] && y[a]+y[d]==y[b]+y[c]);
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++) cin >> x[i] >> y[i];
	int C = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			dx[C] = x[j]-x[i];
			dy[C] = y[j]-y[i];
			di[C] = i, dj[C] = j;
			
			if(dx[C]<0 || (dx[C]==0 && dy[C]<0))
				dx[C] *= -1, dy[C] *= -1;
			cid[C] = C;
			C++;
		}
	}
	sort(cid,cid+C,cmp);
	long long ans = 0;
	int num = 0;
	for(int i=0;i<C;i++)
	{
//		cout << dx[cid[i]] << ' ' << dy[cid[i]] << '\n';
		if(i>0 && (dx[cid[i]]!=dx[cid[i-1]] || dy[cid[i]]!=dy[cid[i-1]]))
			num = 0;
		ans += num;
		num++;
		if(num>1)
		{
			//if(!ispar(di[cid[i]],dj[cid[i]],di[cid[i-1]],dj[cid[i-1]]))
				//cout << di[cid[i]] << ' ' << dj[cid[i]] << ' ' << di[cid[i-1]] << ' ' << dj[cid[i-1]] << '\n';
		}
	}
	cout << ans/2 << '\n';
}