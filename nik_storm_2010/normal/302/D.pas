var
    a,x,y:array[1..100] of longint; used:array[1..10000,1..100] of boolean; path:array[1..100] of longint;
      q:array[1..2,1..10000] of longint; n,d,i,sq,eq,left,middle,right:longint;


procedure addq(x,tek:longint);
begin
  q[1,eq]:=x; q[2,eq]:=tek;
  inc(eq);
end;


procedure outq(var x,tek:longint);
begin
  x:=q[1,sq]; tek:=q[2,sq];
  inc(sq);
end;


function maybe(tek:longint):boolean;
var dist,nom,i:longint;
begin
  for i:=1 to n do begin used[1,i]:=false; path[i]:=-maxlongint; end;
  used[1,1]:=true; sq:=1; eq:=1; addq(1,tek);
  while sq<>eq do
    begin
      outq(nom,tek);
      for i:=1 to n do
        if used[sq-1,i]=false then
        begin
          dist:=(abs(x[i]-x[nom])+abs(y[i]-y[nom]))*d;
          if (tek-dist>=0) and (path[i]<tek-dist+a[i]) then
            begin
              path[i]:=tek-dist+a[i]; used[eq]:=used[sq-1];
              used[eq,i]:=true; addq(i,path[i]);
            end;
        end;
    end;
  if path[n]<>-maxlongint then maybe:=true else maybe:=false;
end;


begin

  readln(n,d);
  for i:=2 to n-1 do read(a[i]); readln;
  for i:=1 to n do readln(x[i],y[i]);
  left:=0; right:=round(1e9);
  while right-left>1 do
    begin
      middle:=(left+right) div 2;
      if maybe(middle) then right:=middle else left:=middle;
    end;
  if maybe(left) then writeln(left) else writeln(right);

end.