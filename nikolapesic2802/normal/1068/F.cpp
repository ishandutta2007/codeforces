#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
int n;
bool inside(int x,int y)
{
    if(x<n&&y<n)
        return true;
    return false;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<int,int> > lol={
		{
			0,0
		},
		{
			1,3
		},
		{
			2,0
		},
		{
			3,3
		},
		{
			4,0
		},
		{
			5,3
		},
		{
			1,0
		},
		{
			3,0
		},
		{
			5,0
		}
	};
	int tr=6;
	for(int i=0;i<9&&i<n;i++)
	 printf("%i %i\n",lol[i].first,lol[i].second);
	 for(int i=9;i<n;i++)
	 {
 		if(i%3==0)
 		{
 			printf("%i %i\n",tr,0);
 			tr++;
 		}
 		if(i%3==1)
 		{
 			printf("%i %i\n",tr,0);
 		}
 		if(i%3==2)
 		{
 			printf("%i %i\n",tr,3);
 			tr++;
 		}
 	}
    return 0;
}