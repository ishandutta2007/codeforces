#include<bits/stdc++.h>

#define N 1000005 

#define mk make_pair 

using namespace std;

set<int>st;

map<int,int> Smaller,Bigger;

int a[N];

void Main()
{
		Smaller.clear();
		Bigger .clear();
		st.clear(); int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
		st.insert(a[1]);
		for (int i = 2; i <= n; ++i)
		{
			if (a[i] == a[i - 1]) Smaller[a[i]] ++, Bigger[a[i]] ++;
			if (a[i] < a[i - 1])
			{
				set<int>::iterator it = st.find(a[i - 1]);
				if (it != st.begin())
				{
					--it;
					if (*it == a[i]) 
					{
						Smaller[a[i]] += Smaller[a[i - 1]] + 2; 
						Smaller[a[i-1]] = 0;
					}
					else if (*it > a[i]) 
					{
						puts("NO");
						return;
					}
					else
					{
						st.insert(a[i]);
						Smaller[a[i]] += Smaller[a[i - 1]] + 1;
						Smaller[a[i - 1]] = 0;
					}
				}
				else
				{
					st.insert(a[i]);	
					Smaller[a[i]] += Smaller[a[i - 1]] + 1;
					Smaller[a[i - 1]] = 0;
				}
			}
			if (a[i] > a[i - 1])
			{
				set<int>::iterator it = st.find(a[i - 1]);
				++it;
				if (it != st.end()) 
				{
					if (*it == a[i])
					{
						Bigger[a[i]] += Bigger[a[i - 1]] + 2;
						Bigger[a[i - 1]] = 0;
					}
					else if (*it < a[i]) 
					{
						puts("NO");
						return;
					}
					else
					{
						st.insert(a[i]);
						Bigger[a[i]] += Bigger[a[i - 1]] + 1;
						Bigger[a[i - 1]] = 0;
					}
				}
				else
				{
					st.insert(a[i]);
					Bigger[a[i]] += Bigger[a[i - 1]] + 1;
					Bigger[a[i - 1]] = 0;
				}
			}			
		}
		puts("YES");
}

int main()
{
	int T; scanf("%d",&T);
	for (;T--;) Main(); 
}