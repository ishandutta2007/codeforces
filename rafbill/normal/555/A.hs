module Main where

import Data.List
import Data.Bool
import Data.Maybe
import Control.Applicative
import Control.Monad

rl :: Read a => IO [a]
rl = fmap read . words <$> getLine

red i [] = []
red i (x:xs) | i == x = red (i+1) xs
             | otherwise = (x:xs)

main :: IO ()
main = do
  [n, k] <- rl :: IO [Int]
  fmap ((+1).sum) (forM [1..k] (const (fmap ((subtract 1).(* 2).length.red 1.tail) rl)))
    >>= print
  pure ()