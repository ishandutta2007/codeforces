#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> aPrimes;
set<int> P;
int isLegal[100001];

int check(int x)
{
	for(int i=0;i<aPrimes.size();i++)
	{
		if((aPrimes[i]*aPrimes[i])>x)
			break;
		if((x%aPrimes[i])==0)
			return 0;
	}
	return 1;
}

void findPrimes(int mx)
{
	aPrimes.push_back(2);
	P.insert(1);
	for(int i=3;i<=mx;i+=2)
		if(check(i))
		{
			aPrimes.push_back(i);
			P.insert(i-1);
		}
}
int prev(int val)
{
	 set<int>::iterator it = P.upper_bound(val);
	 if(it!=P.begin())
		 return *(--it);
	 return -1;
}
int numSwaps(int dif)
{
	if(dif==0) return 0;
	return 1+numSwaps(dif-prev(dif));
}
#include <map>
multimap<int,int> heap;	//val->id
vector<int> A;
int aIndex[100000];
vector<int> ans1;
vector<int> ans2;
void bubble(int iDest)
{
	multimap<int,int>::iterator it1 = heap.begin();
	int iMin = aIndex[it1->second];
	if(iMin==iDest)
	{
		heap.erase(it1);
		return;
	}
	int iNext = iMin - prev(iMin-iDest);
	multimap<int,int>::iterator it2 = heap.find(A[iNext]);
	aIndex[it1->second] = aIndex[it2->second];
	aIndex[it2->second] = iMin;
	int temp = A[iMin];
	A[iMin] = A[iNext];
	A[iNext] = temp;
	ans1.push_back(iNext+1);
	ans2.push_back(iMin+1);
	if(iNext==iDest)
	{
		heap.erase(it1);
		return;
	}
	bubble(iDest);
}

struct Element
{
	int val;
	int index;
};

bool operator<(Element a,Element b)
{
	if(a.val==b.val)
		return a.index<b.index;
	return a.val<b.val;
}

int main()
{
	int N;
	
	int i,j,k;
	Element e;
	cin >> N;
	for(i=0;i<N;i++)
	{
		cin >> j;
		A.push_back(j);
		heap.insert(pair<int,int>(j,i));
		aIndex[i] = i;
	}
	findPrimes(N);
	for(i=0;i<N;i++)
		bubble(i);
	cout << ans1.size() << endl;
	for(i=0;i<ans1.size();i++)
	{
		cout << ans1[i] << " " << ans2[i] << endl;
	}
}