#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define SEG (1<<19)

int Q;
int m[300000],b[300000];
int tp[300000],q[300000];
int rem[300000];

vector<int> seg[2*SEG];
vector<int> lst[2*SEG];
int l[2*SEG],r[2*SEG];

bool cmp(int x,int y)
{
	return m[x] < m[y];
}

double inter(int i,int j)
{
	return (b[j]-b[i])/((double)(m[i]-m[j]));
}

void setify(int r)
{
/*	if(seg[r].size()>0)
		cout << "Segment " << r << '\n';*/
	sort(seg[r].begin(),seg[r].end(),cmp);
	for(int i=0;i<seg[r].size();i++)
	{
//		cout << m[seg[r][i]] << ' ' << b[seg[r][i]] << '\n';
		if(lst[r].size()>0 && m[lst[r].back()] == m[seg[r][i]] && b[lst[r].back()] >= b[seg[r][i]])
			continue;
		if(lst[r].size()>0 && m[lst[r].back()] == m[seg[r][i]])
			lst[r].pop_back();
		while(lst[r].size()>1 && inter(lst[r][lst[r].size()-2],lst[r].back()) >= inter(lst[r].back(),seg[r][i]))
			lst[r].pop_back();
		lst[r].push_back(seg[r][i]);
	}
}

long long evl(int i,int x)
{
	return m[i]*((long long)x)+b[i];
}

int getMax(int lo,int hi,int r,int x)
{
	if(lo==hi) return lo;
	if(lo+1==hi)
	{
		if(inter(lst[r][lo],lst[r][hi]) >= x) return lo;
		else return hi;
	}
	int mid = (lo+hi)/2;
	if(inter(lst[r][mid],lst[r][mid+1]) >= x) return getMax(lo,mid,r,x);
	else return getMax(mid+1,hi,r,x);
}

void init()
{
	for(int i=SEG;i<2*SEG;i++) l[i] = r[i] = i-SEG;
	for(int i=SEG-1;i>0;i--) l[i] = l[2*i], r[i] = r[2*i+1];
}

int low,high;
void insert(int i,int j)
{
	if((l[i]>high)||(r[i]<low)) return;
	if((l[i]>=low)&&(r[i]<=high))
	{
		seg[i].push_back(j);
		return;
	}
	insert(2*i,j);
	insert(2*i+1,j);
}

long long segMax(int i,int x)
{
	i += SEG;
	long long ans = -2000000000000000000LL;
	for(;i>0;i/=2)
	{
		if(lst[i].size()>0)
			ans = max(ans,evl(lst[i][getMax(0,lst[i].size()-1,i,x)],x));
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		cin >> tp[i];
		if(tp[i]==1)
		{
			cin >> m[i] >> b[i];
			rem[i] = Q;
		}
		else if(tp[i]==2)
		{
			cin >> rem[i];
			rem[rem[i]-1] = i;
		}
		else
			cin >> q[i];
	}
	init();
	for(int i=0;i<Q;i++)
	{
		if(tp[i]==1)
		{
			low = i, high = rem[i];
			insert(1,i);
			//cout << i << ' ' << rem[i] << ": " << m[i] << ' ' << b[i] << '\n';
		}
	}
	for(int i=1;i<2*SEG;i++)
	{
		setify(i);
		//cout << i << '\n';
	}
	
	for(int i=0;i<Q;i++)
	{
		if(tp[i]==3)
		{
			long long ans = segMax(i,q[i]);
			if(ans == -2000000000000000000LL) cout << "EMPTY SET\n";
			else cout << ans << '\n';
		}
	}
}