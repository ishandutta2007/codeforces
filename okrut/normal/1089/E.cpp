#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf

typedef long long ll;
typedef pair<int, int> pii;

void move(pii p)
{
	cout << ((char) (p.fi + 'a' - 1)) << p.se << " ";
}

int main()
{
	int n;
	cin >> n;
	
	pii curr = {1, 1};
	bool gora = true;
	
	move(curr);
		
	for(int i = n; i >= 0; i--)
	{
		if(i == 2)
		{
			if(curr.se == 8)
			{
				curr.fi++;
				move(curr);
				move({8, 8});
				return 0;
			}
			else
			{
				curr.fi = 8;
				move(curr);
				curr.se = 8;
				move(curr);
				return 0;
			}
		}
		
		if(gora)
			curr.se++;
		else
			curr.se--;
		
		if(curr.se == 9)
		{
			curr.se = 8;
			curr.fi++;
			gora = false;
		}
		if(curr.se == 0)
		{
			curr.se = 1;
			curr.fi++;
			gora = true;
		}
		
		if(curr.fi == 7)
		{
			curr = {8, 1};
			move(curr);
			i--;
			
			bool lewo = true;
			while(true)
			{
				if(i == 2)
				{
					if(curr.fi == 8)
					{
						curr.se++;
						move(curr);
						move({8, 8});
					}
					else
					{
						move({7, 8});
						move({8, 8});
					}
					return 0;
				}
				
				if(lewo)
					curr.fi--;
				else
					curr.fi++;
				
				if(curr.fi == 6)
				{
					curr.fi = 7;
					lewo = false;
					curr.se++;
				}
				if(curr.fi == 9)
				{
					curr.fi = 8;
					lewo = true;
					curr.se++;
				}
				
								
				if(curr.se == 6)
				{
					if(i == 3)
					{
						cout << "g6 h6 h8";
					}
					else if(i == 4)
					{
						cout << "g8 g6 h6 h8";
					}
					else if(i == 5)
					{
						cout << "g8 g7 g6 h6 h8";
					}
					else if(i == 6)
					{
						cout << "g8 g7 g6 h6 h7 h8";
					}
					return 0;
				}
				
				move(curr);
				i--;
			}
		}
		
		move(curr);
	}
	
	return 0;
}