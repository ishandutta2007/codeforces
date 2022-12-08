										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define NN 900


int cap[NN][NN];
double cost[NN][NN];
int fnet[NN][NN], adj[NN][NN], deg[NN];
int par[NN], q[NN], inq[NN], qs;
double d[NN], pi[NN];

#define CLR(a, x) memset( a, x, sizeof( a ) )
#define Inf (INT_MAX/2)
#define BUBL { t = q[i]; q[i] = q[j]; q[j] = t; t = inq[q[i]]; inq[q[i]] = inq[q[j]]; inq[q[j]] = t; }
#define Pot(u,v) (d[u] + pi[u] - pi[v])

bool dijkstra( int n, int s, int t )
{
	for(int i = 0; i < n; i++)
		d[i] = 1000000;
    CLR( par, -1 );
    CLR( inq, -1 );
    d[s] = qs = 0;
    inq[q[qs++] = s] = 0;
    par[s] = n;
    while( qs ) 
    {
        int u = q[0]; inq[u] = -1;
        q[0] = q[--qs];
        if( qs ) inq[q[0]] = 0;
        for( int i = 0, j = 2*i + 1, t; j < qs; i = j, j = 2*i + 1 )
        {
            if( j + 1 < qs && d[q[j + 1]] < d[q[j]] ) j++;
            if( d[q[j]] >= d[q[i]] ) break;
            BUBL;
        }
        for( int k = 0, v = adj[u][k]; k < deg[u]; v = adj[u][++k] )
        {
            if( fnet[v][u] && d[v] > Pot(u,v) - cost[v][u] ) 
                d[v] = Pot(u,v) - cost[v][par[v] = u];
            if( fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v] ) 
                d[v] = Pot(u,v) + cost[par[v] = u][v];
            if( par[v] == u )
            {
                if( inq[v] < 0 ) { inq[q[qs] = v] = qs; qs++; }
                for( int i = inq[v], j = ( i - 1 )/2, t;
                     d[q[i]] < d[q[j]]; i = j, j = ( i - 1 )/2 )
                     BUBL;
            }
        }
    }
    for( int i = 0; i < n; i++ ) if( pi[i] < Inf ) pi[i] += d[i];
    return par[t] >= 0;
}
#undef Pot

int mcmf4( int n, int s, int t, double &fcost )
{
    CLR( deg, 0 );
    for( int i = 0; i < n; i++ )
    for( int j = 0; j < n; j++ ) 
        if( cap[i][j] || cap[j][i] ) adj[i][deg[i]++] = j;
    CLR( fnet, 0 );
	for(int i = 0; i < n; i++)
		pi[i] = 0;
    int flow = 0;
	fcost = 0;
    while( dijkstra( n, s, t ) ) 
    {
        int bot = INT_MAX;
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            bot = min(bot, fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] ));
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            if( fnet[v][u] ) { fnet[v][u] -= bot; fcost -= bot * cost[v][u]; }
            else { fnet[u][v] += bot; fcost += bot * cost[u][v]; }
        flow += bot;
    }
    return flow;
}

int n;
double x[410], y[410];

double dist(int a, int b){
	double dx = x[a] - x[b];
	double dy = y[a] - y[b];
	return sqrt(dx * dx + dy * dy);
}

int main(){
    memset( cap, 0, sizeof( cap ) );
	cin >> n;
    int s = 2 * n, t = 2 * n + 1;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++){
		cap[s][i] = 2;
		cap[i + n][t] = 1;
		for(int j = 0; j < n; j++){
			if(y[j] >= y[i]) continue;
			cap[i][j + n] = 1;
			cost[i][j + n] = dist(i, j);
		}
	}
    double fcost;
    int flow = mcmf4( 2 * n + 2, s, t, fcost );
	if(flow == n - 1){
		cout.precision(12);
		cout.setf(ios::fixed | ios::showpoint);
		cout << fcost << endl;
	}
	else cout << -1 << endl;
    return 0;
}