var
    a,b,kol:array[1..100000] of longint; n,m,i,j,q,ans,nom:longint; zn:char;



begin

  readln(n,m);
  for i:=1 to m do
    begin
      read(zn); readln(nom);
      if zn='+' then
        begin
          if kol[nom]=1 then
            begin
              writeln('Already on');
            end
              else
            begin
              q:=round(sqrt(nom)); ans:=-1;
              for j:=1 to q do
                begin
                  if nom mod j = 0 then
                    begin
                      if (a[j]=1) and (j<>1) then begin ans:=b[j]; break; end;
                      if (a[nom div j]=1) and (nom div j<>1) then begin ans:=b[nom div j]; break; end;
                    end;
                end;
              if ans = -1 then
                begin
                  writeln('Success'); kol[nom]:=1;
                  for j:=1 to q do
                    begin
                      if nom mod j = 0 then
                        begin
                          a[j]:=1; b[j]:=nom;
                          a[nom div j]:=1; b[nom div j]:=nom;
                        end;
                    end;
                end
                  else
                begin
                  writeln('Conflict with ',ans);
                end;
            end;
        end
          else
        begin
          if kol[nom]=0 then
            begin
              writeln('Already off');
            end
              else
            begin
              q:=round(sqrt(nom)); kol[nom]:=0;
              for j:=1 to q do
                begin
                  if nom mod j = 0 then
                    begin
                      a[j]:=0; a[nom div j]:=0;
                    end;
                end;
              writeln('Success');
            end;
        end;
    end;

end.