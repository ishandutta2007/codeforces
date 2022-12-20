#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int color[100000];
long long size[100000];
int ai[100000];

bool cmp(int a,int b)
{
	if(color[a]==color[b])
		return size[a]>size[b];
	return color[a]<color[b];
}

vector<vector<int> > A;
vector<vector<long long> > sm;
int high[100001];
vector<long long> best;

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> color[i] >> size[i];
		ai[i] = i;
	}
	sort(ai,ai+N,cmp);
	A.push_back(vector<int>());
	sm.push_back(vector<long long>());
	int C = -1;
	for(int i=0;i<N;i++)
	{
		if((i==0)||(color[ai[i]] != color[ai[i-1]]))
		{
			C++;
			A.push_back(vector<int>());
			sm.push_back(vector<long long>());
			A[C].push_back(ai[i]);
			sm[C].push_back(size[ai[i]]);
		}
		else
		{
			A[C].push_back(ai[i]);
			sm[C].push_back(sm[C][sm[C].size()-1]+size[ai[i]]);
		}
	}
	C++;
	for(int i=0;i<100001;i++)
		high[i] = -1;
	int k;
	int ia,ib,na,nb;
	long long ctot = 0;
	for(int i=0;i<C;i++)
	{
		best.push_back(0);
		k = A[i].size();
		for(int j=0;j<k;j++)
		{
			if((j>=1)&&(high[j-1] != -1))
			{
				best[i] = max(best[i],sm[i][j]+sm[high[j-1]][j-1]);
				if(best[i] > ctot)
				{
					ia = high[j-1];
					ib = i;
					na = j-1;
					nb = j;
					ctot = best[i];
				}
			}
			if(high[j] != -1)
			{
				best[i] = max(best[i],sm[i][j]+sm[high[j]][j]);
				if(best[i] > ctot)
				{
					ia = high[j];
					ib = i;
					na = j;
					nb = j;
					ctot = best[i];
				}
			}
			if(high[j+1] != -1)
			{
				best[i] = max(best[i],sm[i][j]+sm[high[j+1]][j+1]);
				if(best[i] > ctot)
				{
					ia = high[j+1];
					ib = i;
					na = j+1;
					nb = j;
					ctot = best[i];
				}
			}
		}
		for(int j=0;j<k;j++)
			if((high[j]==-1)||(sm[high[j]][j] < sm[i][j]))
				high[j] = i;
	}
	na++,nb++;
	cout << ctot << endl;
	cout << na+nb << endl;
	int curi;
	if(na<nb) curi = ib;
	else curi = ia;
	for(int i=0;i<na+nb;i++)
	{
		cout << A[curi][i/2]+1 << " ";
		if(curi == ia) curi = ib;
		else curi = ia;
	}
}