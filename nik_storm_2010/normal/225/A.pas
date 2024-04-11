var
    a:array[1..2,1..100] of longint; tek:set of byte;
      pred,n,i,j:longint;


begin

  readln(n); readln(pred); readln(a[1,1],a[2,1]);
  for i:=2 to n do
    begin
      readln(a[1,i],a[2,i]); tek:=[];
      for j:=1 to 2 do
        case a[j,i] of
          1: tek:=tek+[1]+[6]; 6: tek:=tek+[1]+[6];
          2: tek:=tek+[2]+[5]; 5: tek:=tek+[2]+[5];
          3: tek:=tek+[3]+[4]; 4: tek:=tek+[3]+[4];
        end;
      if pred in tek then begin writeln('NO'); halt; end;
    end;
  writeln('YES');

end.