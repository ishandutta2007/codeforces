var
    a,b:array[1..1000] of longint; n,m,max,min,i,tek:longint;


procedure findmax(var nom:longint);
  var tek,i:longint;
begin
  tek:=0; nom:=0;
  for i:=1 to m do
    begin
      if tek<a[i] then
        begin
          tek:=a[i]; nom:=i;
        end;
    end;
end;


procedure findmin(var nom:longint);
  var tek,i:longint;
begin
  tek:=maxlongint; nom:=0;
  for i:=1 to m do
    begin
      if (tek>b[i]) and (b[i]<>0) then
        begin
          tek:=b[i]; nom:=i;
        end;
    end;
end;


begin

  readln(n,m);
  for i:=1 to m do
    begin
      read(tek);
      a[i]:=tek; b[i]:=tek;
    end;

  max:=0; min:=0;
  for i:=1 to n do
    begin
      findmax(tek); max:=max+a[tek]; dec(a[tek]);
      findmin(tek); min:=min+b[tek]; dec(b[tek]);
    end;
  writeln(max,' ',min);

end.