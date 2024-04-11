var
    mas:array[1..2,0..20] of longint; nn,n,d,i:int64;


function num(nom:longint):int64;
  var ans:int64; i:longint;
begin
  ans:=0; for i:=mas[nom,0] downto 1 do ans:=ans*10+mas[nom,i]; num:=ans;
end;


procedure decri(nom:longint);
  var i:longint;
begin
  mas[2,nom]:=9; i:=nom+1;
  while mas[2,i]=0 do begin mas[2,i]:=9; inc(i); end;
  if (i=mas[2,0]) and (mas[2,i]=1) then dec(mas[2,0]);
  dec(mas[2,i]);
end;


begin

  readln(n,d); nn:=n;
  while nn<>0 do
    begin
      inc(mas[1,0]); mas[1,mas[1,0]]:=nn mod 10;
      nn:=nn div 10;
    end;

  i:=1;
  while i<=mas[1,0] do
    begin
      if mas[1,i]=9 then
        begin
          inc(i);
        end
          else
        begin
          if i=mas[1,0] then break
            else
              begin
                mas[2]:=mas[1]; decri(i);
                if (n-num(2)) <= d then
                  begin
                    mas[1]:=mas[2]; inc(i);
                  end else break;
              end;
        end;
    end;
  writeln(num(1));

end.