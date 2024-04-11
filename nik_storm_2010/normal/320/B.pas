var
  int:array[1..2,1..100] of longint; g:array[1..100,1..100] of longint;
  i,j,x,y,c,a,b,n,k:longint;


begin

  readln(n);
  for i:=1 to n do
  begin
    readln(c,a,b);
    if c=1 then
    begin
      inc(k); int[1,k]:=a; int[2,k]:=b; g[k,k]:=1;
      for x:=1 to k-1 do
      begin
        if (int[1,x]<a) and (a<int[2,x]) then g[k,x]:=1;
        if (int[1,x]<b) and (b<int[2,x]) then g[k,x]:=1;
        if (a<int[1,x]) and (int[1,x]<b) then g[x,k]:=1;
        if (a<int[2,x]) and (int[2,x]<b) then g[x,k]:=1;
      end;
      for j:=1 to k do
        for x:=1 to k do
          for y:=1 to k do
          if (g[x,j]=1) and (g[j,y]=1) then g[x,y]:=1;
    end
      else
    begin
      if (g[a,b]=1) then writeln('YES') else writeln('NO');
    end;
  end;

end.