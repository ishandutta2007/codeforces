var
    kolx,koly,i:longint; c:char;


begin

  kolx:=0; koly:=0;
  while not(eoln) do
    begin
      read(c);
      if c='x' then inc(kolx) else inc(koly);
    end;
  if kolx>koly then c:='x' else c:='y';
  for i:=1 to abs(kolx-koly) do write(c);

end.