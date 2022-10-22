#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;


int main()
{

	std::vector<int> farg;
	std::vector<ll> deg;
	ll k, z, n, m, x, y, a, b, c, w;


	ll V, B;
	bool fail;

	int c1, c2, c3, c4, c5, c6, c7;

	std::cin >> n >> m;

	std::vector<std::vector<ll> > C(n, std::vector<ll>());

	for (c1 = 0; c1 < n; c1++){

		deg.push_back(0);
		farg.push_back(-1);

	}

	for (c1 = 0; c1 < m; c1++){

		std::cin >> a >> b;
		a--;
		b--;

		C[a].push_back(b);
		C[b].push_back(a);

		deg[a]++;
		deg[b]++;

	}

	ll maxdeg = 0;

	for (c1 = 0; c1 < n; c1++){

		if (deg[c1] > maxdeg){
			maxdeg = deg[c1];



		}
	}

		ll anst;
		ll answ;
		if (maxdeg == 0){

			anst = 3ll;
			answ = round((n*(n - 1)*(n - 2)) / 6);
		}
		if (maxdeg == 1){

			ll zeros = 0;
			ll ones = 0;
			for (c1 = 0; c1 < n; c1++){

				if (deg[c1] == 0){ zeros++; }
				else{ ones++; }


			}

			anst = 2ll;

			answ = round((n - 2)*(ones) / 2);


		}

		if (maxdeg > 1){

			fail = 0;
			anst = 1ll;
            answ=0;
            //BFS
            std::queue<ll> Q;
			for (ll i = 0; i < n; i++){


            if(farg[i] == -1){
                V=1;
                B=0;
                farg[i] = 0;
                while(Q.size()!=0){Q.pop();}
                Q.push(i);

                while(Q.size()>0){

                    a=Q.front();
                    Q.pop();

                    for(c2=0;c2<deg[a];c2++){

                        b=C[a][c2];
                        if(farg[b]==-1){

                            farg[b] = (farg[a]+1)%2;
                            if(farg[b]==0){V++;}
                            else{B++;}
                            Q.push(b);

                        }
                        else{
                            if(farg[b] == farg[a]){fail=1;}

                        }

                    }

                }

                answ += round((V*(V-1) + B*(B-1))/2);



            }

			}
            //

		}
    if(fail==1){anst=0;answ=1;}
    std::cout << anst << " " << answ << "\n";
		return 0;
	}