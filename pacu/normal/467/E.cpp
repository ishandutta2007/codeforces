#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define INF 1000000007
int first[524288][20];

void setFirst(int i,int f)
{
	first[i][0] = f;
	for(int j=1;j<20;j++)
	{
		i /= 2;
		first[i][j] = min(first[2*i][j-1],first[2*i+1][j-1]);
	}
}

inline int lPoint(int i,int j)
{
	return i<<j;
}

inline int rPoint(int i,int j)
{
	return ((i+1)<<j) - 1;
}

int gm(int i,int j,int l,int r)
{
	if((lPoint(i,j)==l)&&(rPoint(i,j)==r))
		return first[i][j];
	int mn = INF;
	if(l <= rPoint(2*i,j-1))
		mn = min(mn,gm(2*i,j-1,l,min(r,rPoint(2*i,j-1))));
	if(r >= lPoint(2*i+1,j-1))
		mn = min(mn,gm(2*i+1,j-1,max(l,lPoint(2*i+1,j-1)),r));
	return mn;
}

int getMin(int l,int r)
{
	return gm(0,19,l,r);
}

void init()
{
	for(int i=0;i<524288;i++)
		for(int j=0;j<20;j++)
			first[i][j] = i;
}

int A[500000];
int main()
{
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for(int j=0;j<N;j++)
		cin >> A[j];
	int i = 0;
	vector<int> ans;
	while(i<N)
	{
		map<int,int> last;
		map<int,int> cnt;
		//init();
		for(;i<N;i++)
		{
			int c,prev;
			if(last.find(A[i])==last.end())
			{
				setFirst(i,i);
				last[A[i]] = i;
				cnt[A[i]] = 1;
				continue;
			}

			prev = last[A[i]];
			setFirst(i,first[prev][0]);
			c = getMin(prev+1,i-1);
			if(c < prev)
			{
				ans.push_back(A[c]);
				ans.push_back(A[i]);
				ans.push_back(A[c]);
				ans.push_back(A[i]);
			}

			if(c<prev)
			{
				i++;
				break;
			}

			last[A[i]] = i;
			cnt[A[i]]++;
			if(cnt[A[i]]==4)
			{
				for(int p=0;p<4;p++)
					ans.push_back(A[i]);
				i++;
				break;
			}
		}
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	return 0;
}