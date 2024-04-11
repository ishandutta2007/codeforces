var
n:longint;
matr:array[1..3000,1..3000] of boolean;
dist:array[1..3000] of longint;
pred:array[1..3000] of longint;
mark:array[1..3000] of boolean;
i:longint;
v1,v2:longint;

procedure dfs(x:longint);
var
  i:longint;
  temp:longint;
begin
  for i:=1 to n do
    if matr[x,i] then
    begin
      if (pred[i]<>0) and (i<>pred[x]) and (dist[i]<>0) then
      begin
        temp:=x;
        while temp<>i do
        begin
       //   writeln(temp,' ',i);
          dist[temp]:=0;
          temp:=pred[temp];
        end;
        dist[temp]:=0;
      end
      else if (i<>pred[x]) and (dist[i]<>0) then
      begin
        pred[i]:=x;
        dfs(i);
      end;
    end;
end;

procedure dfs2(x:longint;jarak:longint);
var
  i:longint;
begin
  mark[x]:=true;
  dist[x]:=jarak;
  for i:=1 to n do
    if (matr[x,i]) and (dist[i]<>0) and not (mark[i]) then
      dfs2(i,jarak+1);
end;


begin
readln(n);
for i:=1 to n do
begin
  readln(v1,v2);
  matr[v1,v2]:=true;
  matr[v2,v1]:=true;
end;
for i:=1 to n do
  dist[i]:=-1;
pred[1]:=2000000000;
dfs(1);
for i:=1 to n do
  if dist[i]=0 then
    dfs2(i,0);
for i:=1 to n do
begin
  write(dist[i]);
  if i<n then write(' ');
end;
writeln;
end.