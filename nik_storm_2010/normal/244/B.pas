var
    a,b:array[0..10] of longint; used:array[0..9] of boolean; answer,n,i:longint;


function compare(kol:longint):boolean;
var j:longint;
begin
  if kol<a[0] then exit(true);
  for j:=a[0] downto 1 do
    begin
      if a[j]>b[j] then exit(true);
      if a[j]<b[j] then exit(false);
    end;
  exit(true);
end;


procedure rec(nom,dif:longint);
var j:longint;
begin
  if nom=i+1 then
    begin
      if compare(nom-1)=true then inc(answer);
    end
      else
    begin
      for j:=0 to 9 do
        begin
          if (j=0) and (nom=i) then continue;
          if used[j]=true then
            begin
              b[nom]:=j; rec(nom+1,dif);
            end
              else
            begin
              if dif<2 then
                begin
                  used[j]:=true; b[nom]:=j;
                  rec(nom+1,dif+1);
                  used[j]:=false;
                end;
            end;
        end;
    end;
end;


begin

  readln(n); answer:=0;
  while n<>0 do
    begin
      inc(a[0]); a[a[0]]:=n mod 10;
      n:=n div 10;
    end;
  for i:=1 to a[0] do
  rec(1,0);
  writeln(answer);

end.