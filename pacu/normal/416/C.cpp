#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct req
{
	int sz,pay,id;
};

struct table
{
	int sz,id;
};

bool cmp(req a,req b)
{
	if(a.pay==b.pay)
		return a.sz<b.sz;
	return a.pay>b.pay;
}

bool cmp2(table a,table b)
{
	return a.sz < b.sz;
}

int main()
{
	int N,K;
	req R[1000];
	table A[1000];
	bool used[1000];
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> R[i].sz >> R[i].pay;
		R[i].id = i;
	}
	cin >> K;
	for(int i=0;i<K;i++)
	{
		cin >> A[i].sz;
		A[i].id = i;
		used[i] = 0;
	}
	sort(R,R+N,cmp);
	sort(A,A+K,cmp2);
	vector<int> reqs;
	vector<int> tables;
	int tot = 0;
	for(int i=0;i<N;i++)
	{
		int j;
		for(j=0;j<K;j++)
			if((!used[j])&&(A[j].sz >= R[i].sz))
				break;
		if(j < K)
		{
			reqs.push_back(R[i].id);
			tables.push_back(A[j].id);
			tot += R[i].pay;
			used[j] = 1;
		}
	}
	cout << reqs.size() << " " << tot << endl;
	for(int i=0;i<reqs.size();i++)
		cout << reqs[i]+1 << " " << tables[i]+1 << endl;
	return 0;
}