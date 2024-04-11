#include <bits/stdc++.h>
int n, a, b, c, ost;
std::bitset<4007> mog;
main()
{
	std::cin>>n>>a>>b>>c;
	mog[0]=1;
	for (int i=1; i<=n; i++)
		if ((mog=((mog<<a)|(mog<<b)|(mog<<c)))[n])
			ost=i;
	std::cout << ost;
}