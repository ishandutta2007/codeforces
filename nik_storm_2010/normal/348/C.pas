const
  big=100000;
  lim=320;
var
  f:array[1..big] of array of longint;
  was:array[1..lim,1..big] of boolean;
  g:array[1..big,1..lim] of longint;
  list:array[1..lim] of longint;
  bad:array[1..big] of boolean;
  l,a,sum,add:array[1..big] of int64;
  size,n,m,q,i,j,k:longint;
  ans,now,x,y:int64;
  kind:char;

begin
  readln(n,m,q);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do
  begin
    read(l[i]);
    setlength(f[i],l[i]+1);
    now:=0;
    for j:=1 to l[i] do
    begin
      read(f[i,j]);
      now:=now+a[f[i,j]];
    end;
    readln;
    sum[i]:=now;
    if (l[i]>lim) then
    begin
      bad[i]:=true;
      inc(size);
      list[size]:=i;
      for j:=1 to l[i] do was[size,f[i,j]]:=true;
    end;
  end;
  for i:=1 to m do for j:=1 to size do
  begin
    now:=0;
    for k:=1 to l[i] do if (was[j,f[i,k]]) then inc(now);
    g[i,j]:=now;
  end;
  for i:=1 to q do
  begin
    read(kind);
    case kind of
    '?':
    begin
      readln(x);
      if (bad[x]) then writeln(sum[x]) else
      begin
        ans:=0;
        for j:=1 to l[x] do ans:=ans+a[f[x,j]];
        for j:=1 to size do ans:=ans+add[list[j]]*g[x,j];
        writeln(ans);
      end;
    end;
    '+':
    begin
      readln(x,y);
      if (bad[x]) then
      begin
        add[x]:=add[x]+y;
        for j:=1 to size do sum[list[j]]:=sum[list[j]]+y*g[x,j];
      end
        else
      begin
        for j:=1 to l[x] do a[f[x,j]]:=a[f[x,j]]+y;
        for j:=1 to size do sum[list[j]]:=sum[list[j]]+y*g[x,j];
      end;
    end;
    end;
  end;
end.