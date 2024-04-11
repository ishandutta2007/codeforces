uses
  math;
const
  maximum=100000;
  log=17;
type
  edges=record too,nxt:longint; end;
var
  parent:array[1..maximum,0..log] of longint;
  line:array[1..2*maximum] of edges;
  leng,deep,start,tin,tout,list:array[1..maximum] of longint;
  red:array[1..maximum] of boolean;
  time,size,cnt,lim,ans,num,n,m,i,j,k,x,y:longint;

procedure add(x,y:longint);
begin
  inc(cnt);
  line[cnt].too:=y;
  line[cnt].nxt:=start[x];
  start[x]:=cnt;
end;

procedure prepare(nom,prev,dp:longint);
var
  i:longint;
begin
  deep[nom]:=dp;
  inc(time);
  tin[nom]:=time;
  parent[nom,0]:=prev;
  for i:=1 to log do parent[nom,i]:=parent[parent[nom,i-1],i-1];
  i:=start[nom];
  while (i<>0) do
  begin
    if (line[i].too<>prev) then prepare(line[i].too,nom,dp+1);
    i:=line[i].nxt;
  end;
  inc(time);
  tout[nom]:=time;
end;

procedure find;
var
  query:array[1..2,1..maximum] of longint;
  used:array[1..maximum] of boolean;
  st,fn,x,y,i,e:longint;
begin
  fillchar(used,sizeof(used),false);
  st:=1; fn:=1;
  for i:=1 to n do if (red[i]) then
  begin
    query[1,fn]:=i;
    query[2,fn]:=0;
    inc(fn);
    used[i]:=true;
  end;
  while (st<>fn) do
  begin
    x:=query[1,st];
    y:=query[2,st];
    inc(st);
    leng[x]:=y;
    e:=start[x];
    while (e<>0) do
    begin
      if (not used[line[e].too]) then
      begin
        query[1,fn]:=line[e].too;
        query[2,fn]:=y+1;
        inc(fn);
        used[line[e].too]:=true;
      end;
      e:=line[e].nxt;
    end;
  end;
end;

function ancestor(x,y:longint):boolean;
begin
  if (tin[x]<=tin[y]) and (tout[y]<=tout[x]) then exit(true);
  ancestor:=false;
end;

function lca(x,y:longint):longint;
var
  i:longint;
begin
  if (ancestor(x,y)) then exit(x);
  if (ancestor(y,x)) then exit(y);
  for i:=log downto 0 do if (not ancestor(parent[x,i],y)) then x:=parent[x,i];
  lca:=parent[x,0];
end;

begin
  readln(n,m);
  for i:=1 to n-1 do
  begin
    readln(x,y);
    add(x,y);
    add(y,x);
  end;
  prepare(1,1,1);
  lim:=round(sqrt(m));
  i:=1;
  red[1]:=true;
  while (i<=m) do
  begin
    find;
    size:=0;
    for j:=i to min(i+lim-1,m) do
    begin
      read(x,y);
      if (x=1) then
      begin
        inc(size);
        list[size]:=y;
        red[y]:=true;
      end
        else
      begin
        ans:=leng[y];
        for k:=1 to size do
        begin
          num:=lca(y,list[k]);
          ans:=min(ans,deep[list[k]]-deep[num]+deep[y]-deep[num]);
        end;
        writeln(ans);
      end;
    end;
    i:=i+lim;
  end;
end.