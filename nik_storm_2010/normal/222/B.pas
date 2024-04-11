uses math;
var
   a:array[1..1000,1..1000] of longint; b,d:array[1..1000] of longint;
     n,m,k,i,j,x,y,t:longint; c:char;

begin

  readln(n,m,k);
  for i:=1 to n do
    begin
      for j:=1 to m do read(a[i,j]);
      readln;
    end;
  for i:=1 to max(n,m) do begin b[i]:=i; d[i]:=i; end;

  for i:=1 to k do
    begin
      readln(c,x,y);
      if c='g' then
        begin
          writeln(a[b[x],d[y]]);
        end
          else
        begin
          if c='c' then
            begin
              t:=d[x]; d[x]:=d[y]; d[y]:=t;
            end
              else
            begin
              t:=b[x]; b[x]:=b[y]; b[y]:=t;
            end;
        end;
    end;

end.